// var  → 不要用，是历史遗留写法，LeetCode 模板里有但实际项目不用

// const → 优先用，只要这个变量不需要重新赋值
const n = nums.length;   // 不会变，用 const
const arr = new Array(n) // 数组引用不会变，用 const
const idx = ch => ...    // 函数不会变，用 const

// let → 只有需要重新赋值时才用
let ans = 0;     // 后面 ans = Math.max(...) 会重新赋值，用 let
let left = 0;    // 后面 left++ 会重新赋值，用 let
let tmp = "";    // 后面 tmp = tmp.slice(...) 会重新赋值，用 let
```

---

### 一句话总结
```
var   → 不用
const → 默认用这个
let   → 需要重新赋值时才换成 let



// ============ 1. 函数声明 ============
function add(a, b) {
    return a + b;
}
// 特点：有变量提升，可以在声明之前调用
add(1, 2); // ✅ 即使写在声明前面也能用


// ============ 2. 函数表达式 ============
const add = function(a, b) {
    return a + b;
};
// 特点：没有变量提升，必须先声明再调用
// LeetCode 模板用的就是这种（用 var）


// ============ 3. 箭头函数 ============
const add = (a, b) => {
    return a + b;
};

// 只有一行返回值时可以简写，省略 {} 和 return
const add = (a, b) => a + b;

// 只有一个参数时可以省略括号
const double = n => n * 2;

// 没有参数时括号不能省略
const greet = () => "hello";


// ============ 4. 匿名函数（直接传入作为参数）============
// 不赋值给变量，直接作为参数传给另一个函数
[1, 2, 3].map(function(n) {
    return n * 2;
});

// 实际上箭头函数更常用
[1, 2, 3].map(n => n * 2); // [2, 4, 6]



好问题，从**为什么需要闭包**来理解比直接讲概念更清晰。

---

### 问题一：怎么创建私有变量

```javascript
// 假设你在写一个计数器
let count = 0;  // 全局变量，任何地方都能修改

function increment() {
    count++;
}

// 问题：count 暴露在外面，任何人都能改
count = 9999;   // ❌ 被外部随意篡改
increment();
console.log(count); // 10000，结果不可控
```

用闭包解决：

```javascript
function createCounter() {
    let count = 0;  // 私有变量，外部无法直接访问

    return {
        increment: () => ++count,
        decrement: () => --count,
        getCount:  () => count,
    };
}

const counter = createCounter();
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.getCount();  // 1

// count 在外部完全访问不到，只能通过暴露的方法操作
count;               // ❌ 报错，count is not defined
```

---

### 问题二：函数需要记住状态

```javascript
// 假设你要生成唯一 ID
// 不用闭包：需要一个全局变量记录当前 ID
let currentId = 0;
function generateId() {
    return ++currentId;
}
// currentId 暴露在外面，容易被篡改

// 用闭包：状态藏在函数内部
function createIdGenerator() {
    let currentId = 0;          // 状态藏在这里，外部看不到

    return () => ++currentId;   // 每次调用自动递增
}

const generateId = createIdGenerator();
generateId(); // 1
generateId(); // 2
generateId(); // 3
```

---

### 问题三：函数工厂，批量生成相似函数

```javascript
// 假设你需要多个不同倍数的乘法函数
// 不用闭包：每个函数都要单独写
function double(n)  { return n * 2; }
function triple(n)  { return n * 3; }
function times10(n) { return n * 10; }

// 用闭包：一个工厂函数批量生成
function multiply(factor) {
    // factor 被内部函数记住了
    return n => n * factor;
}

const double  = multiply(2);
const triple  = multiply(3);
const times10 = multiply(10);

double(5);  // 10
triple(5);  // 15
times10(5); // 50
```

---

### 一句话总结闭包的作用

```
1. 创建私有变量，防止外部篡改
2. 让函数记住状态，不依赖全局变量
3. 函数工厂，批量生成相似函数
```

本质上闭包解决的是同一个问题：**把数据和操作数据的函数绑定在一起，隐藏内部细节**。这和 C++ 里 class 的封装思想是一样的，只是实现方式不同。

```cpp
// C++ 用 class 封装
class Counter {
private:
    int count = 0;        // 私有变量
public:
    int increment() { return ++count; }
    int getCount()  { return count; }
};

// JS 用闭包封装
function createCounter() {
    let count = 0;        // 私有变量
    return {
        increment: () => ++count,
        getCount:  () => count,
    };
}
```

Promise 是将“生产者代码”和“消费者代码”连接在一起的一个特殊的 JavaScript 对象。用我们的类比来说：这就是就像是“订阅列表”。
state: pending, fulfilled, rejected

.then .catch 注册消费函数
.then的参数是一个函数
.catch 处理error
.finally 不管成功与否都会处理


Promise.all(promises) —— 等待所有 promise 都 resolve 时，返回存放它们结果的数组。如果给定的任意一个 promise 为 reject，那么它就会变成 Promise.all 的 error，所有其他 promise 的结果都会被忽略。
Promise.allSettled(promises)（ES2020 新增方法）—— 等待所有 promise 都 settle 时，并以包含以下内容的对象数组的形式返回它们的结果：
status: "fulfilled" 或 "rejected"
value（如果 fulfilled）或 reason（如果 rejected）。
Promise.race(promises) —— 等待第一个 settle 的 promise，并将其 result/error 作为结果返回。
Promise.any(promises)（ES2021 新增方法）—— 等待第一个 fulfilled 的 promise，并将其结果作为结果返回。如果所有 promise 都 rejected，Promise.any 则会抛出 AggregateError 错误类型的 error 实例。
Promise.resolve(value) —— 使用给定 value 创建一个 resolved 的 promise。
Promise.reject(error) —— 使用给定 error 创建一个 rejected 的 promise。


async function f() {
  return 1;
}
即这个函数总是返回一个 promise。其他值将自动被包装在一个 resolved 的 promise 中。
await 只在async方法内工作
await 使 JavaScript 引擎等待该 promise settle，然后：