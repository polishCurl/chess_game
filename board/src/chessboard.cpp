#include "board/src/chessboard.hpp"

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

Chessboard::Chessboard() {
  PieceFactory piece_factory;

  for (const auto& el : kPieceMap) {
    getPiece(el.first) =
        piece_factory.create(el.second.first, el.first, el.second.second);
  }
}

int Chessboard::getPieceCount(Color color, PieceType type) const { return 0; }

MoveResult Chessboard::move(Color player_color, const Move& move) {
  auto& piece = getPiece(move.curr_pos_);
  auto& target_piece = getPiece(move.next_pos_);

  if (!piece) {
    return MoveResult::kInvalid;
  }

  if (piece->getColor() != player_color) {
    return MoveResult::kInvalid;
  }

  if (!piece->canMove(move.next_pos_)) {
    return MoveResult::kInvalid;
  }

  if ((piece->getType() != PieceType::kKnight) && detectColision(move)) {
    return MoveResult::kInvalid;
  }

  if (!target_piece) {
    piece->move(move.next_pos_);
    target_piece = std::move(piece);
    return MoveResult::kNoCapture;
  }

  if (target_piece->getColor() == player_color) {
    return MoveResult::kInvalid;
  } else {
    target_piece.reset(nullptr);
    piece->move(move.next_pos_);
    target_piece = std::move(piece);
    return MoveResult::kCapture;
  }

  return MoveResult::kInvalid;
}

std::unique_ptr<IPiece>& Chessboard::getPiece(const Position& position) {
  return board_[position.row_][position.col_];
}

bool Chessboard::detectColision(const chess::common::Move& move) {
  for (const auto& position : Move::getIntermediatePositions(move)) {
    if (getPiece(position)) {
      return true;
    }
  }
  return false;
}

}  // namespace board
}  // namespace chess
