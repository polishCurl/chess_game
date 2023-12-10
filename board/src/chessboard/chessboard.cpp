#include "src/chessboard/chessboard.hpp"

#include "piece/src/piece_factory/piece_factory.hpp"

namespace chess {
namespace board {

using namespace chess::common;
using namespace chess::piece;

const PieceMap Chessboard::kPieceMap{
    {Position{"A1"}, {PieceType::kRook, Color::White}},
    {Position{"B1"}, {PieceType::kKnight, Color::White}},
    {Position{"C1"}, {PieceType::kBishop, Color::White}},
    {Position{"D1"}, {PieceType::kQueen, Color::White}},
    {Position{"E1"}, {PieceType::kKing, Color::White}},
    {Position{"F1"}, {PieceType::kBishop, Color::White}},
    {Position{"G1"}, {PieceType::kKnight, Color::White}},
    {Position{"H1"}, {PieceType::kRook, Color::White}},

    {Position{"A2"}, {PieceType::kPawn, Color::White}},
    {Position{"B2"}, {PieceType::kPawn, Color::White}},
    {Position{"C2"}, {PieceType::kPawn, Color::White}},
    {Position{"D2"}, {PieceType::kPawn, Color::White}},
    {Position{"E2"}, {PieceType::kPawn, Color::White}},
    {Position{"F2"}, {PieceType::kPawn, Color::White}},
    {Position{"G2"}, {PieceType::kPawn, Color::White}},
    {Position{"H2"}, {PieceType::kPawn, Color::White}},

    {Position{"A8"}, {PieceType::kRook, Color::Black}},
    {Position{"B8"}, {PieceType::kKnight, Color::Black}},
    {Position{"C8"}, {PieceType::kBishop, Color::Black}},
    {Position{"D8"}, {PieceType::kQueen, Color::Black}},
    {Position{"E8"}, {PieceType::kKing, Color::Black}},
    {Position{"F8"}, {PieceType::kBishop, Color::Black}},
    {Position{"G8"}, {PieceType::kKnight, Color::Black}},
    {Position{"H8"}, {PieceType::kRook, Color::Black}},

    {Position{"A7"}, {PieceType::kPawn, Color::Black}},
    {Position{"B7"}, {PieceType::kPawn, Color::Black}},
    {Position{"C7"}, {PieceType::kPawn, Color::Black}},
    {Position{"D7"}, {PieceType::kPawn, Color::Black}},
    {Position{"E7"}, {PieceType::kPawn, Color::Black}},
    {Position{"F7"}, {PieceType::kPawn, Color::Black}},
    {Position{"G7"}, {PieceType::kPawn, Color::Black}},
    {Position{"H7"}, {PieceType::kPawn, Color::Black}},
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
      ((piece->getType() != PieceType::kKnight) && detectColision(move)) ||
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
