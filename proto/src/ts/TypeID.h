

#pragma once


#include "general.h"
#include "Kind.h"


namespace ts {


	using TypeID = uint32_t;

	// Will need this if we wanted to expose it to C API.
	constexpr TypeID noType = -1;


	// Starting from ID 0, each Kind, respectively, will be allocated
	// 10'000 IDs for types thereof.
	// This makes it so we can deduce the kind of a type by its ID.
	constexpr TypeID firstTypeOfKind(Kind k) noexcept {
		return TypeID(k) * 10'000;
	}
	// If K is the first ID of k, this fn returns TypeID(K + offset).
	constexpr TypeID typeByKind(Kind k, uint32_t offset) noexcept {
		return firstTypeOfKind(k) + offset;
	}
	constexpr std::optional<Kind> kindByType(TypeID x) noexcept {
		if (x < enumSize<Kind> * 10'000) {
			return Kind(x / 10'000);
		}
		return std::nullopt;
	}
	constexpr std::optional<uint32_t> kOffsetOfType(TypeID x) noexcept {
		if (auto k = kindByType(x)) {
			return x - firstTypeOfKind(*k);
		}
		return std::nullopt;
	}
	static_assert(typeByKind(Kind::Fn, 1'402) == 31'402);
	static_assert(kindByType(31'402) == Kind::Fn);
	static_assert(kOffsetOfType(31'402) == 1'402);


	// C-style enum (treated like a namespace) for builtin Yama
	// type IDs.
	// Gonna use PascalCase for these so they don't conflict w/
	// C++ keywords.
	enum ids : TypeID {
		NoneType = firstTypeOfKind(Kind::Prim),
		IntType,
		UIntType,
		FloatType,
		BoolType,
		// Not 100% if I want to rename Rune to Char.
		CharType,
		TypeType,
		NeverType,
	};

	inline std::string fmtTypeID(TypeID x) {
		if (x == noType)					return "<NoType>";
		else if (x == NoneType)				return "None";
		else if (x == IntType)				return "Int";
		else if (x == UIntType)				return "UInt";
		else if (x == FloatType)			return "Float";
		else if (x == BoolType)				return "Bool";
		else if (x == CharType)				return "Char";
		else if (x == TypeType)				return "Type";
		else if (x == NeverType)			return "Never";
		else if (auto k = kindByType(x))	return std::format("<{}({})>", fmtKind(*k), x);
		else								return std::format("<Unknown({})>", x);
	}
}

