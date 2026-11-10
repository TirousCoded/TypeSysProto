

#pragma once


#include <assert.h>
#include <cstdint>
#include <format>
#include <iostream>
#include <optional>
#include <string>
#include <type_traits>


// NOTE: Below code is currently Windows/MSVC only.


#define TS_UNREACHABLE __assume(false)
#define TS_ASSERT(x) assert(x)


namespace ts {


	using SSize = std::make_signed_t<size_t>;

	template<typename T>
	concept SizedEnum =
		requires
	{
		{ T::Num } -> std::convertible_to<std::underlying_type_t<T>>;
	};
	template<typename T>
	constexpr auto enumSize = (size_t)(std::underlying_type_t<T>)T::Num;

	template<typename... Args>
	inline void print(std::format_string<Args...> fmt, Args&&... args) {
		std::cout << std::format(fmt, std::forward<Args>(args)...);
	}
	template<typename... Args>
	inline void println(std::format_string<Args...> fmt, Args&&... args) {
		std::cout << std::format(fmt, std::forward<Args>(args)...) << '\n';
	}

	// Use '[[noreturn]]' on fns which return Never.
	class Never final {
	public:
		Never() = delete;


		template<typename T>
		[[noreturn]] constexpr operator T() const noexcept {
			TS_UNREACHABLE;
		}
	};

	[[noreturn]] inline Never breakpoint() noexcept {
		__debugbreak();
		TS_UNREACHABLE;
	}
	template<typename... Args>
	[[noreturn]] inline Never panic(std::format_string<Args...> fmt, Args&&... args) {
		println("Panic: {}", std::format(fmt, std::forward<Args>(args)...));
		breakpoint();
	}
	[[noreturn]] inline Never panic() {
		panic("Error!");
	}
}

