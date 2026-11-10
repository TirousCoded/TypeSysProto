

#pragma once


#include "general.h"


namespace ts {


	enum class Kind : uint8_t {
		Parcel,
		Var,
		VarAssign,
		Fn,
		Coroutine,
		Prim,
		Struct,
		Choice,
		Alt,
		Prop,
		PropAssign,
		Method,
		Proto,
		ProtoProp,
		ProtoMethod,
		Conv,
		// Oper fns for things like '+'.
		// These have special param-based method overloading.
		// Part of this is implicit coercions to param types are disabled.
		Oper,

		Num,
	};

	constexpr const char* fmtKind(Kind k) noexcept {
		static_assert(enumSize<Kind> == 17);
		switch (k) {
#define _CASE_(x) case Kind:: x : return #x
			_CASE_(Parcel);
			_CASE_(Var);
			_CASE_(VarAssign);
			_CASE_(Fn);
			_CASE_(Coroutine);
			_CASE_(Prim);
			_CASE_(Struct);
			_CASE_(Choice);
			_CASE_(Alt);
			_CASE_(Prop);
			_CASE_(PropAssign);
			_CASE_(Method);
			_CASE_(Proto);
			_CASE_(ProtoProp);
			_CASE_(ProtoMethod);
			_CASE_(Conv);
			_CASE_(Oper);
#undef _CASE_
		default: return "<Unknown>";
		}
	}
}

