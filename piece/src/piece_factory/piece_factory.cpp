#include "src/piece_factory/piece_factory.hpp"

#include "src/bishop/bishop.hpp"
#include "src/king/king.hpp"
#include "src/knight/knight.hpp"
#include "src/pawn/pawn.hpp"
#include "src/queen/queen.hpp"
#include "src/rook/rook.hpp"

namespace chess {

namespace piece {

using namespace chess::common;

std::unique_ptr<IPiece> PieceFactory::create(PieceType type,
                                             const Position& position,
                                             Color color) const {
  switch (type) {
    case PieceType::kPawn:
      return std::make_unique<Pawn>(position, color);
    case PieceType::kKnight:
      return std::make_unique<Knight>(position, color);
    case PieceType::kBishop:
      return std::make_unique<Bishop>(position, color);
    case PieceType::kRook:
      return std::make_unique<Rook>(position, color);
    case PieceType::kQueen:
      return std::make_unique<Queen>(position, color);
    case PieceType::kKing:
      return std::make_unique<King>(position, color);
    default:
      return nullptr;
  }
}

}  // namespace piece
}  // namespace chess