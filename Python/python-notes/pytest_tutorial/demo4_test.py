import pytest


@pytest.fixture
def hello():
    print("start hello world")
    yield 66
    print("end hello world")


class Test_Demo4:
    def test_case1(self):
        print("run test_case1")
        assert 2 + 2 == 4

    def test_case2(self, hello):
        print("run test_case2")
        print(hello)
        assert 1 + 12 == 13

    def test_case3(self):
        print("run test_case3")
        assert 199 + 1 == 200


if __name__ == "__main__":
    pytest.main()
