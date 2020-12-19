
# 104ms 8.89% 209.6MB 97.78%
# iterative dynamic programming
# O(HW) O(HW)
def unique_paths(h, w)
  c = Array.new(h) { Array.new(w, 0) }
  c[0][0] = 1
  for y in 0..(h-1)
    for x in 0..(w-1)
      if y > 0 then
        c[y][x] += c[y-1][x]
      end
      if x > 0 then
        c[y][x] += c[y][x-1]
      end
    end
  end
  return c[h-1][w-1]
end
