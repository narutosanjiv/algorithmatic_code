
arr = []

#Algorithm taken from Wiki
def mergesort(list)
  return list if list.size <= 1
  mid   = list.size / 2
  left  = list[0, mid]
  right = list[mid, list.size]
  merge(mergesort(left), mergesort(right))
end

def merge(left, right)
  sorted = []
  until left.empty? || right.empty?
    if left.first <= right.first
      sorted << left.shift
    else
      sorted << right.shift
    end
  end
  sorted.concat(left).concat(right)
end


mode = "r+"
File.open("DuplicateIntegerArray.txt", mode).each_line do|line|
  arr.push(line.to_i)
end

sorted_arr = mergesort(arr)

File.open("SortedIntegerArrayRuby.txt", "w") do|f|
  f.puts(sorted_arr)
end
