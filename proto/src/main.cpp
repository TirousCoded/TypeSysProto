

#include "ts/general.h"
#include "ts/TypeID.h"
#include "ts/TypeCtx.h"


/*
	Prototype Type System Features:

		- Parcels will now be types.
			- Maybe decouple types so they don't NEED parcels?
				- So impl w/out parcels first.
		
		- Uses uint IDs for each type.
			- Reserved IDs for builtins.
			- Pseudo-IDs for generic params + others meta stuff.
			- Able to deduce things like 'kind' from ID value.
		
		- ECS-esque 'descriptors' mapped to IDs.

		- Can ID types by string 'specifiers'.
			- Parsed into nice AST.
				- Then interpreted w/ stack machine layer.

			- Should we NOT have each type have one specific
			  signature string unique to it?
				- Not sure.

		- Types will be organized into a hierarchical namespace, w/
		  an anonymous base namespace.
			- Example:
				+ Int
				+ UInt
				+ Vec2
				  + x
				    + assign
				  + y
				    + assign

			- How would we specify parcels here?

			- Each type can have a 'depth' uint showing how deeply
			  nested it is.
				- Then, each depth can have an associated set of
				  pseudo-IDs for things like type params.
					- This gives us multi-level generics, w/ nested
					  types having nice access to type params of the
					  generic types it's nested within.

		- Have some central 'context' for loading types.
			- Should be really easy to use.

		- Kinds of types:
			- Parcels
			- Vars
				- Var. Assigners
			- Fns
			- Coroutines
			- Primitives
			- Structs
			- Choices (ie. Named Unions)
				- Alts
			- Properties
				- Prop. Assigners
			- Methods
			- Protocols
				- Property Req.
				- Method Req.
			- Conversions
			- Operators
*/


int32_t factorial(int32_t x) noexcept {
	if (x == 0)			return 1;
	else if (x >= 1)	return x * factorial(x - 1);
	else				return ts::panic();
}

int32_t main(int32_t argc, char** argv) {

	ts::println("{}", ts::fmtTypeID(ts::noType));
	ts::println("{}", ts::fmtTypeID(ts::NoneType));
	ts::println("{}", ts::fmtTypeID(ts::UIntType));
	ts::println("{}", ts::fmtTypeID(ts::NeverType));
	ts::println("{}", ts::fmtTypeID(ts::typeByKind(ts::Kind::Choice, 301)));
	ts::println("{}", ts::fmtTypeID(ts::typeByKind(ts::Kind::Fn, 14)));
	ts::println("{}", ts::fmtTypeID(ts::typeByKind(ts::Kind::PropAssign, 1041)));
	ts::println("{}", ts::fmtTypeID(6'010'000));

	return 0;
}

