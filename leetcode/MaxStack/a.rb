# stack
# 136ms 100.00% 213.3MB 71.43%
class MaxStack
    def initialize()
      @stck = []
    end

    def push(x)
      @stck.push(x)
    end

    def pop()
      return @stck.pop()
    end

    def top()
      return @stck.last
    end

    def peek_max()
      return @stck.max()
    end

    def pop_max()
      e = peek_max()
      @stck.delete_at(@stck.rindex(e))
      return e
    end
end
