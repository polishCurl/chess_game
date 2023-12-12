#include "src/chessboard/chessboard.hpp"

#include "piece/src/piece_factory/piece_factory.hpp"

namespace chess {
namespace board {

using namespace chess::common;
using namespace chess::piece;

const PieceMap Chessboard::kPieceMap{
    {Position{"A1"}, {PieceType::Rook, Color::White}},
    {Position{"B1"}, {PieceType::Knight, Color::White}},
    {Position{"C1"}, {PieceType::Bishop, Color::White}},
    {Position{"D1"}, {PieceType::Queen, Color::White}},
    {Position{"E1"}, {PieceType::King, Color::White}},
    {Position{"F1"}, {PieceType::Bishop, Color::White}},
    {Position{"G1"}, {PieceType::Knight, Color::White}},
    {Position{"H1"}, {PieceType::Rook, Color::White}},

    {Position{"A2"}, {PieceType::Pawn, Color::White}},
    {Position{"B2"}, {PieceType::Pawn, Color::White}},
    {Position{"C2"}, {PieceType::Pawn, Color::White}},
    {Position{"D2"}, {PieceType::Pawn, Color::White}},
    {Position{"E2"}, {PieceType::Pawn, Color::White}},
    {Position{"F2"}, {PieceType::Pawn, Color::White}},
    {Position{"G2"}, {PieceType::Pawn, Color::White}},
    {Position{"H2"}, {PieceType::Pawn, Color::White}},

    {Position{"A8"}, {PieceType::Rook, Color::Black}},
    {Position{"B8"}, {PieceType::Knight, Color::Black}},
    {Position{"C8"}, {PieceType::Bishop, Color::Black}},
    {Position{"D8"}, {PieceType::Queen, Color::Black}},
    {Position{"E8"}, {PieceType::King, Color::Black}},
    {Position{"F8"}, {PieceType::Bishop, Color::Black}},
    {Position{"G8"}, {PieceType::Knight, Color::Black}},
    {Position{"H8"}, {PieceType::Rook, Color::Black}},

    {Position{"A7"}, {PieceType::Pawn, Color::Black}},
    {Position{"B7"}, {PieceType::Pawn, Color::Black}},
    {Position{"C7"}, {PieceType::Pawn, Color::Black}},
    {Position{"D7"}, {PieceType::Pawn, Color::Black}},
    {Position{"E7"}, {PieceType::Pawn, Color::Black}},
    {Position{"F7"}, {PieceType::Pawn, Color::Black}},
    {Position{"G7"}, {PieceType::Pawn, Color::Black}},
    {Position{"H7"}, {PieceType::Pawn, Color::Black}},
};

void Chessboard::reset() {
  for (auto& row : board_) {
    for (auto& slot : row) {
      slot.reset(nullptr);
    }
  }

  for (const auto& el : kPieceMap) {
    static_cast<void>(addPiece(el.second.first, el.second.second, el.first));
  }
}

const chess::piece::IPiece* Chessboard::getPiece(
    const chess::common::Position& position) {
  return getPieceInternal(position).get();
}

bool Chessboard::addPiece(chess::piece::PieceType type,
                          chess::common::Color color,
                          const chess::common::Position& position) {
  auto& piece = getPieceInternal(position);
  if (piece) {
    return false;
  }

  piece = PieceFactory{}.create(type, position, color);
  return true;
}

bool Chessboard::removePiece(const chess::common::Position& position) {
  auto& piece = getPieceInternal(position);

  if (!piece) {
    return false;
  }

  piece.reset(nullptr);
  return true;
}

bool Chessboard::movePiece(Color player_color, const Move& move) {
  auto& piece = getPieceInternal(move.curr_pos_);
  auto& target_piece = getPieceInternal(move.next_pos_);

  if (!piece || (piece->getColor() != player_color) ||
      !piece->canMove(move.next_pos_) ||
      (!piece->canJump() && detectColision(move)) ||
      (target_piece && (target_piece->getColor() == player_color))) {
    return false;
  }

  piece->move(move.next_pos_);
  target_piece = std::move(piece);
  return true;
}

bool Chessboard::detectColision(const chess::common::Move& move) {
  for (const auto& position : Move::getIntermediatePositions(move)) {
    if (getPiece(position)) {
      return true;
    }
  }
  return false;
}

std::unique_ptr<chess::piece::IPiece>& Chessboard::getPieceInternal(
    const chess::common::Position& position) {
  return board_[position.row_][position.col_];
}

}  // namespace board
}  // namespace chess
