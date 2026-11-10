

#pragma once


#include "general.h"
#include "Kind.h"
#include "TypeID.h"


namespace ts {


	class TypeCtx final {
	public:
		TypeCtx() = default;


		TypeID importParcel(const std::string& path);
		TypeID ldFromParcel(TypeID parcel, const std::string& name);
	};
}

