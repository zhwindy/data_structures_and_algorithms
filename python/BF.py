#!/usr/bin/env python
# encoding=UTF-8


def bf(string_S, string_T):
    """
    字符串的模式匹配
    """
    s_len = len(string_S)
    t_len = len(string_T)
    for i in range(s_len - 1):
        k = i
        j = 0
        while (string_S[k] == string_T[j]):
            k += 1
            j += 1
            if j == t_len:
                return i
    return 0


def bf_1(string_S, string_T):
    """
    字符串的模式匹配
    """
    s_len = len(string_S)
    t_len = len(string_T)
    i = 0
    j = 0
    while(i < s_len and j < t_len):
        if string_S[i] == string_T[j]:
            i += 1
            j += 1
        else:
            j = 0
            i = i - j + 1
    if j >= t_len:
        return i - t_len
    return 0


def main(st, rt):
    # pos_1 = bf(st, rt)
    pos = bf_1(st, rt)
    return pos


if __name__ == "__main__":
    st = "Ilovezhaypqngfei.coldlar.cc we love bitcoin"
    rt = "coin"
    print(main(st, rt))
