﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2016 Ryo Suzuki
//	Copyright (C) 2016 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <functional>
# include "Optional.hpp"

namespace s3d
{
	////////////////////////////////////////////////////////////////
	//
	//		==
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryEqualX
		{
			const TypeY& y;

			constexpr BinaryEqualX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) == y))
			{
				return std::forward<TypeX>(x) == y;
			}
		};

		template <class TypeX>
		struct BinaryEqualY
		{
			const TypeX& x;

			constexpr BinaryEqualY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x == std::forward<TypeY>(y)))
			{
				return x == std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto Equal() noexcept
	{
		return std::equal_to<>();
	}

	template <class TypeX>
	inline constexpr auto Equal(TypeX&& x) noexcept
	{
		return detail::BinaryEqualY<TypeX>{x};
	}

	template <class TypeX, class TypeY>
	inline constexpr auto Equal(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) == std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) == std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto Equal(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryEqualX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto Equal(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryEqualY<TypeX>{x};
	}

	inline constexpr auto Equal(nullopt_t, nullopt_t) noexcept
	{
		return std::equal_to<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		!=
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryNotEqualX
		{
			const TypeY& y;

			constexpr BinaryNotEqualX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) != y))
			{
				return std::forward<TypeX>(x) != y;
			}
		};

		template <class TypeX>
		struct BinaryNotEqualY
		{
			const TypeX& x;

			constexpr BinaryNotEqualY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x != std::forward<TypeY>(y)))
			{
				return x != std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto NotEqual() noexcept
	{
		return std::not_equal_to<>();
	}

	template <class TypeX>
	inline constexpr auto NotEqual(TypeX&& x) noexcept
	{
		return detail::BinaryNotEqualY<TypeX>{x};
	}

	template <class TypeX, class TypeY>
	inline constexpr auto NotEqual(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) != std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) != std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto NotEqual(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryNotEqualX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto NotEqual(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryNotEqualY<TypeX>{x};
	}

	inline constexpr auto NotEqual(nullopt_t, nullopt_t) noexcept
	{
		return std::not_equal_to<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		<
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryLessThanX
		{
			const TypeY& y;

			constexpr BinaryLessThanX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) < y))
			{
				return std::forward<TypeX>(x) < y;
			}
		};

		template <class TypeX>
		struct BinaryLessThanY
		{
			const TypeX& x;

			constexpr BinaryLessThanY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x < std::forward<TypeY>(y)))
			{
				return x < std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto LessThan() noexcept
	{
		return std::less<>();
	}

	template <class TypeY>
	inline constexpr auto LessThan(TypeY&& y) noexcept
	{
		return detail::BinaryLessThanX<TypeY>{y};
	}

	template <class TypeX, class TypeY>
	inline constexpr auto LessThan(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) < std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) < std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto LessThan(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryLessThanX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto LessThan(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryLessThanY<TypeX>{x};
	}

	inline constexpr auto LessThan(nullopt_t, nullopt_t) noexcept
	{
		return std::less<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		<=
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryLessThanEqualX
		{
			const TypeY& y;

			constexpr BinaryLessThanEqualX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) <= y))
			{
				return std::forward<TypeX>(x) <= y;
			}
		};

		template <class TypeX>
		struct BinaryLessThanEqualY
		{
			const TypeX& x;

			constexpr BinaryLessThanEqualY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x <= std::forward<TypeY>(y)))
			{
				return x <= std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto LessThanEqual() noexcept
	{
		return std::less_equal<>();
	}

	template <class TypeY>
	inline constexpr auto LessThanEqual(TypeY&& y) noexcept
	{
		return detail::BinaryLessThanEqualX<TypeY>{y};
	}

	template <class TypeX, class TypeY>
	inline constexpr auto LessThanEqual(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) <= std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) <= std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto LessThanEqual(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryLessThanEqualX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto LessThanEqual(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryLessThanEqualY<TypeX>{x};
	}

	inline constexpr auto LessThanEqual(nullopt_t, nullopt_t) noexcept
	{
		return std::less_equal<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		>
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryGreaterThanX
		{
			const TypeY& y;

			constexpr BinaryGreaterThanX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) > y))
			{
				return std::forward<TypeX>(x) > y;
			}
		};

		template <class TypeX>
		struct BinaryGreaterThanY
		{
			const TypeX& x;

			constexpr BinaryGreaterThanY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x > std::forward<TypeY>(y)))
			{
				return x > std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto GreaterThan() noexcept
	{
		return std::greater<>();
	}

	template <class TypeY>
	inline constexpr auto GreaterThan(TypeY&& y) noexcept
	{
		return detail::BinaryGreaterThanX<TypeY>{y};
	}

	template <class TypeX, class TypeY>
	inline constexpr auto GreaterThan(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) > std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) > std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto GreaterThan(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryGreaterThanX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto GreaterThan(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryGreaterThanY<TypeX>{x};
	}

	inline constexpr auto GreaterThan(nullopt_t, nullopt_t) noexcept
	{
		return std::greater<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		>=
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryGreaterThanEqualX
		{
			const TypeY& y;

			constexpr BinaryGreaterThanEqualX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) >= y))
			{
				return std::forward<TypeX>(x) >= y;
			}
		};

		template <class TypeX>
		struct BinaryGreaterThanEqualY
		{
			const TypeX& x;

			constexpr BinaryGreaterThanEqualY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x >= std::forward<TypeY>(y)))
			{
				return x >= std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto GreaterThanEqual() noexcept
	{
		return std::greater_equal<>();
	}

	template <class TypeY>
	inline constexpr auto GreaterThanEqual(TypeY&& y) noexcept
	{
		return detail::BinaryGreaterThanEqualX<TypeY>{y};
	}

	template <class TypeX, class TypeY>
	inline constexpr auto GreaterThanEqual(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) >= std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) >= std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto GreaterThanEqual(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryGreaterThanEqualX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto GreaterThanEqual(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryGreaterThanEqualY<TypeX>{x};
	}

	inline constexpr auto GreaterThanEqual(nullopt_t, nullopt_t) noexcept
	{
		return std::greater_equal<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		+
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		struct UnaryPlusX
		{
			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(+(std::forward<TypeX>(x))))
			{
				return +(std::forward<TypeX>(x));
			}
		};

		template <class TypeY>
		struct BinaryPlusX
		{
			const TypeY& y;

			constexpr BinaryPlusX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) + y))
			{
				return std::forward<TypeX>(x) + y;
			}
		};

		template <class TypeX>
		struct BinaryPlusY
		{
			const TypeX& x;

			constexpr BinaryPlusY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x + std::forward<TypeY>(y)))
			{
				return x + std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto Plus() noexcept
	{
		return std::plus<>();
	}

	template <class TypeX>
	inline constexpr auto Plus(TypeX&& x) noexcept(noexcept(+(std::forward<TypeX>(x))))
	{
		return +(std::forward<TypeX>(x));
	}

	inline constexpr auto Plus(nullopt_t) noexcept
	{
		return detail::UnaryPlusX();
	}

	template <class TypeX, class TypeY>
	inline constexpr auto Plus(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) + std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) + std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto Plus(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryPlusX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto Plus(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryPlusY<TypeX>{x};
	}

	inline constexpr auto Plus(nullopt_t, nullopt_t) noexcept
	{
		return std::plus<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		-
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		struct UnaryMinusX
		{
			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(-(std::forward<TypeX>(x))))
			{
				return -(std::forward<TypeX>(x));
			}
		};

		template <class TypeY>
		struct BinaryMinusX
		{
			const TypeY& y;

			constexpr BinaryMinusX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) - y))
			{
				return std::forward<TypeX>(x) - y;
			}
		};

		template <class TypeX>
		struct BinaryMinusY
		{
			const TypeX& x;

			constexpr BinaryMinusY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x - std::forward<TypeY>(y)))
			{
				return x - std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto Minus() noexcept
	{
		return std::minus<>();
	}

	template <class TypeX>
	inline constexpr auto Minus(TypeX&& x) noexcept(noexcept(-(std::forward<TypeX>(x))))
	{
		return -(std::forward<TypeX>(x));
	}

	inline constexpr auto Minus(nullopt_t) noexcept
	{
		return detail::UnaryMinusX();
	}

	template <class TypeX, class TypeY>
	inline constexpr auto Minus(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) - std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) - std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto Minus(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryMinusX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto Minus(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryMinusY<TypeX>{x};
	}

	inline constexpr auto Minus(nullopt_t, nullopt_t) noexcept
	{
		return std::minus<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		*
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryMultipliesX
		{
			const TypeY& y;

			constexpr BinaryMultipliesX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) * y))
			{
				return std::forward<TypeX>(x) * y;
			}
		};

		template <class TypeX>
		struct BinaryMultipliesY
		{
			const TypeX& x;

			constexpr BinaryMultipliesY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x * std::forward<TypeY>(y)))
			{
				return x * std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto Multiplies() noexcept
	{
		return std::multiplies<>();
	}

	template <class TypeX, class TypeY>
	inline constexpr auto Multiplies(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) * std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) * std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto Multiplies(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryMultipliesX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto Multiplies(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryMultipliesY<TypeX>{x};
	}

	inline constexpr auto Multiplies(nullopt_t, nullopt_t) noexcept
	{
		return std::multiplies<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		/
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryDividesX
		{
			const TypeY& y;

			constexpr BinaryDividesX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) / y))
			{
				return std::forward<TypeX>(x) / y;
			}
		};

		template <class TypeX>
		struct BinaryDividesY
		{
			const TypeX& x;

			constexpr BinaryDividesY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x / std::forward<TypeY>(y)))
			{
				return x / std::forward<TypeY>(y);
			}
		};
	}

	inline constexpr auto Divides() noexcept
	{
		return std::divides<>();
	}

	template <class TypeX, class TypeY>
	inline constexpr auto Divides(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) / std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) / std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto Divides(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryDividesX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto Divides(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryDividesY<TypeX>{x};
	}

	inline constexpr auto Divides(nullopt_t, nullopt_t) noexcept
	{
		return std::divides<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		%
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class TypeY>
		struct BinaryModulusX
		{
			const TypeY& y;

			constexpr BinaryModulusX(const TypeY& _y) noexcept
				: y(_y) {}

			template <class TypeX, std::enable_if_t<!std::is_floating_point<TypeX>::value && !std::is_floating_point<TypeY>::value>* = nullptr>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(std::forward<TypeX>(x) % y))
			{
				return std::forward<TypeX>(x) % y;
			}

			template <class TypeX, std::enable_if_t<std::is_floating_point<TypeX>::value || std::is_floating_point<TypeY>::value>* = nullptr>
			constexpr auto operator()(TypeX&& x) const
			{
				return std::fmod(x, y);
			}
		};

		template <class TypeX>
		struct BinaryModulusY
		{
			const TypeX& x;

			constexpr BinaryModulusY(const TypeX& _x) noexcept
				: x(_x) {}

			template <class TypeY, std::enable_if_t<!std::is_floating_point<TypeX>::value && !std::is_floating_point<TypeY>::value>* = nullptr>
			constexpr auto operator()(TypeY&& y) const noexcept(noexcept(x % std::forward<TypeY>(y)))
			{
				return x % std::forward<TypeY>(y);
			}

			template <class TypeY, std::enable_if_t<std::is_floating_point<TypeX>::value || std::is_floating_point<TypeY>::value>* = nullptr>
			constexpr auto operator()(TypeY&& y) const
			{
				return std::fmod(x, y);
			}
		};
	}

	inline constexpr auto Modulus() noexcept
	{
		return std::modulus<>();
	}

	template <class TypeX, class TypeY>
	inline constexpr auto Modulus(TypeX&& x, TypeY&& y) noexcept(noexcept(std::forward<TypeX>(x) % std::forward<TypeY>(y)))
	{
		return std::forward<TypeX>(x) % std::forward<TypeY>(y);
	}

	template <class TypeY>
	inline constexpr auto Modulus(nullopt_t, TypeY&& y) noexcept
	{
		return detail::BinaryModulusX<TypeY>{y};
	}

	template <class TypeX>
	inline constexpr auto Modulus(TypeX&& x, nullopt_t) noexcept
	{
		return detail::BinaryModulusY<TypeX>{x};
	}

	inline constexpr auto Modulus(nullopt_t, nullopt_t) noexcept
	{
		return std::modulus<>();
	}

	////////////////////////////////////////////////////////////////
	//
	//		&&
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		||
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		!
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		struct UnaryNotX
		{
			template <class TypeX>
			constexpr auto operator()(TypeX&& x) const noexcept(noexcept(!(std::forward<TypeX>(x))))
			{
				return !(std::forward<TypeX>(x));
			}
		};
	}

	inline constexpr auto Not() noexcept
	{
		return std::plus<>();
	}

	template <class TypeX>
	inline constexpr auto Not(TypeX&& x) noexcept(noexcept(!(std::forward<TypeX>(x))))
	{
		return !(std::forward<TypeX>(x));
	}

	inline constexpr auto Not(nullopt_t) noexcept
	{
		return detail::UnaryNotX();
	}

	////////////////////////////////////////////////////////////////
	//
	//		<<
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		>>
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		&
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		|
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		^
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		~
	//
	////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	//
	//		InRange
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		template <class MinType, class MaxType>
		struct InRange_impl
		{
			const MinType& m_min;

			const MaxType& m_max;

			constexpr InRange_impl(const MinType& min, const MaxType& max)
				: m_min(min)
				, m_max(max) {}

			template <class Type>
			constexpr bool operator() (Type&& value) const
			{
				return (m_min <= value) && (value <= m_max);
			}
		};
	}

	template <class MinType, class MaxType>
	inline constexpr auto InRange(MinType&& min, MaxType&& max)
	{
		return detail::InRange_impl<MinType, MaxType>(std::forward<MinType>(min), std::forward<MaxType>(max));
	}

	////////////////////////////////////////////////////////////////
	//
	//		Odd
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		struct Odd_impl
		{
			template <class Type>
			constexpr bool operator()(const Type& x) const
			{
				return (x % 2) != 0;
			}
		};
	}

	inline constexpr auto Odd()
	{
		return detail::Odd_impl();
	}

	inline constexpr auto Odd(nullopt_t)
	{
		return detail::Odd_impl();
	}

	////////////////////////////////////////////////////////////////
	//
	//		Even
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		struct Even_impl
		{
			template <class Type>
			constexpr bool operator()(const Type& x) const
			{
				return (x % 2) == 0;
			}
		};
	}

	inline constexpr auto Even()
	{
		return detail::Even_impl();
	}

	inline constexpr auto Even(nullopt_t)
	{
		return detail::Even_impl();
	}

	////////////////////////////////////////////////////////////////
	//
	//		Id
	//
	////////////////////////////////////////////////////////////////

	namespace detail
	{
		struct Id_impl
		{
			template <class Type>
			constexpr decltype(auto) operator()(Type&& x) const
			{
				return std::forward<Type>(x);
			}
		};
	}

	inline constexpr auto Id()
	{
		return detail::Id_impl();
	}

	inline constexpr auto Id(nullopt_t)
	{
		return detail::Id_impl();
	}
}
