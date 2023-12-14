#include "piece/src/piece_factory/piece_factory.hpp"

#include "piece/src/bishop/bishop.hpp"
#include "piece/src/king/king.hpp"
#include "piece/src/knight/knight.hpp"
#include "piece/src/pawn/pawn.hpp"
#include "piece/src/queen/queen.hpp"
#include "piece/src/rook/rook.hpp"

namespace chess {

namespace piece {

using namespace chess::common;

std::unique_ptr<IPiece> PieceFactory::create(PieceType type,
                                             const Position& position,
                                             Color color) const {
  switch (type) {
    case PieceType::Pawn:
      return std::make_unique<Pawn>(position, color);
    case PieceType::Knight:
      return std::make_unique<Knight>(position, color);
    case PieceType::Bishop:
      return std::make_unique<Bishop>(position, color);
    case PieceType::Rook:
      return std::make_unique<Rook>(position, color);
    case PieceType::Queen:
      return std::make_unique<Queen>(position, color);
    case PieceType::King:
      return std::make_unique<King>(position, color);
    default:
      return nullptr;
  }
}

}  // namespace piece
}  // namespace chess