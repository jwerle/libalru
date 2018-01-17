#include <describe/describe.h>
#include <alru/alru.h>

#define TEST(t) void test_##t()
#define RUN(t) test_##t()

TEST(alru_init) {
  alru_t alru;
  describe("alru_init()") {
    it("should return `ALRU_FALSE` for an empty `alru_t *` pointer.") {
      assert(ALRU_FALSE == alru_init(0, 0, 0));
    }

    it("should return `ALRU_FALSE` when `max` is set to 0.") {
      assert(ALRU_FALSE == alru_init(&alru, 0, 0));
    }

    it("should return `ALRU_TRUE` when `alru_t *` pointer and `max` are non-zero.") {
      assert(ALRU_TRUE == alru_init(&alru, 0, 5));
      assert(ALRU_TRUE == alru_deinit(&alru));
    }
  }
}

int
main(void) {
  RUN(alru_init);
  return assert_failures();
}
