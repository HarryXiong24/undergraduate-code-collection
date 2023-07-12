import functools


@functools.lru_cache(maxsize=128, typed=False)
def job(n):
    # print(n.__hash__())
    print('run very long.....')
    return n + 10000


if __name__ == '__main__':
    print(job([1,2,3]))
    # print(job(1.0))
