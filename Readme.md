
### 📐 Bit Width Constants

| Macro         | Value | Description                  |
|---------------|--------|------------------------------|
| `BitWidth8`   | `0`    | Number fits in 8 bits        |
| `BitWidth16`  | `1`    | Number fits in 16 bits       |
| `BitWidth32`  | `2`    | Number fits in 32 bits       |
| `BitWidth64`  | `3`    | Number requires 64 bits      |

---

### 🧠 Final Utility Macros

| Macro           | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `GetBitWidth(x)` | Returns the `BitWidthX` value needed to store `x` (8/16/32/64 bit decision) |
| `IsOdd(x)`       | Returns `true` if `x` is odd (1, 3, 5...)                                   |
| `IsEven(x)`      | Returns `true` if `x` is even (0, 2, 4...)                                  |
