# @param {String} s
# @return {Integer}

# 56ms 67.21% 209.9MB 96.72%
# iterative dynamic programming
# O(N) O(1)
def num_decodings(s)
  if s.length == 0 or s[0] == '0'
    return 0
  end
  n1, n2 = 1, 0
  for i in 1..(s.length-1)
    m1, m2 = 0, 0
    if s[i] >= '1' and s[i] <= '9'
      m1 = n1 + n2
    end
    n = s[i-1..i].to_i
    if n >= 10 and n <= 26
      m2 = n1
    end
    n1, n2 = m1, m2
  end
  return n1 + n2  
end
