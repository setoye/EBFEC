// MIT License

// Copyright (c) 2020 setoye

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <type_traits>
/// \b bitmask for enum class.
/// specialization for enum class T if needed.
template <typename T>
struct enable_bitmask : std::false_type
{
};

template <
	typename T,
	std::enable_if_t<std::is_enum_v<T> && enable_bitmask<T>::value> * = nullptr>
constexpr T operator|(T lhs, T rhs)
{
	using type = std::underlying_type_t<T>;
	return static_cast<T>(static_cast<type>(lhs) | static_cast<type>(rhs));
}

template <
	typename T,
	std::enable_if_t<std::is_enum_v<T> && enable_bitmask<T>::value> * = nullptr>
constexpr T operator&(T lhs, T rhs)
{
	using type = std::underlying_type_t<T>;
	return static_cast<T>(static_cast<type>(lhs) & static_cast<type>(rhs));
}

/// \brief USAGE: ENABLE_ENUM_BITMASK(T)
#define ENABLE_ENUM_BITMASK(T)                \
	static_assert(std::is_enum_v<T>);         \
	template <>                               \
	struct enable_bitmask<T> : std::true_type \
	{                                         \
	};