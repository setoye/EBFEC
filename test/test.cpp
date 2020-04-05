#include "bitmask.hpp"
#include <cstdint>
/// declare
enum class Fruit : uint32_t
{
	none = 0,
	apple = 1,
	banana = 2,
	orange = 4
};
/// use
ENABLE_ENUM_BITMASK(Fruit);

int main()
{
	constexpr auto v1 = Fruit::apple | Fruit::banana | Fruit::orange;
	constexpr auto v2 = Fruit::apple | Fruit::banana & Fruit::orange;
	constexpr auto v3 = Fruit::apple & Fruit::banana & Fruit::orange;

	static_assert(static_cast<uint32_t>(v1) == 7);
	static_assert((v1 & Fruit::apple) == Fruit::apple);
	static_assert(v2 == Fruit::apple);
	static_assert(v3 == Fruit::none);
	static_assert((v2 & Fruit::banana) == Fruit::none);

	return 0;
}