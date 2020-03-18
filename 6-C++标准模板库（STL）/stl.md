[TOC]

# stl总结

## vector

### 定义

vector\<typename> name，注意如果type为<>，则>>直接要加空格，即 **> >**

可以直接定义为vector\<int> first(4,100)

可以定义二维数组为 vector\<typename> Arrayname[arraysize];

### 访问

1. 下标访问（类似数组）
2. 通过迭代器访问，*(array.begin() + i) == array[i]

### push_back()

往后增加容量

### size()

返回元素个数

### clear()

清空元素，size() == 0

### insert()

在迭代器处插入元素，insert(iter, x), 时间复杂度O(n)

### erase()

1. 删除单个元素，erase(iter)
2. 删除区间内所有元素，erase(iter1, itea2)

### 常见用途

1. 存储数据（作为数组）
2. 作为邻接表存储图