

#pragma once


#include "general.h"


namespace ts {


	class Spec final {
	public:
		Spec() = default;
		Spec(const Spec&) = default;
		Spec(Spec&&) noexcept = default;
		Spec& operator=(const Spec&) = default;
		Spec& operator=(Spec&&) noexcept = default;


		std::string fmt() const;
	};
}

