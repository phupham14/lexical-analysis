# PL/0 Lexer

## Giới thiệu
Bộ phân tích từ vựng (Lexer) cho ngôn ngữ PL/0, được viết bằng C. Chương trình đọc mã nguồn từ tệp `.pl0`, phân tích từng token và hiển thị chúng ra màn hình.

## Cấu trúc thư mục
```
📁 lexer_pl0
   ├── lexer.h         # Định nghĩa token và các hàm lexer
   ├── lexer.c         # Triển khai lexer
   ├── main.c          # Chương trình chính
   ├── test.pl0        # Tệp mã nguồn PL/0 mẫu
   ├── Makefile        # (Tùy chọn) Biên dịch nhanh
   └── README.md       # Hướng dẫn sử dụng
```

## Cài đặt và chạy

### 1. Biên dịch chương trình
Nếu bạn có `Makefile`, chỉ cần chạy lệnh:
```sh
make
```
Nếu không có `Makefile`, hãy biên dịch thủ công:
```sh
gcc -o lexer lexer.c main.c
```

### 2. Chạy lexer
Chạy chương trình với tệp mã nguồn PL/0:
```sh
./lexer test.pl0
```

### 3. Kết quả đầu ra
Chương trình sẽ hiển thị danh sách các token nhận diện được, ví dụ:
```
Token: KEYWORD    Value: VAR
Token: IDENT      Value: x
Token: ASSIGN     Value: :=
Token: NUMBER     Value: 10
Token: SEMICOLON  Value: ;
Token: KEYWORD    Value: IF
Token: IDENT      Value: x
Token: GTR        Value: >
Token: NUMBER     Value: 5
Token: KEYWORD    Value: THEN
Token: IDENT      Value: x
Token: ASSIGN     Value: :=
Token: IDENT      Value: x
Token: PLUS       Value: +
Token: NUMBER     Value: 1
Token: PERIOD     Value: .
Token: EOF        Value: EOF
```

## Dọn dẹp file biên dịch
Nếu bạn sử dụng `Makefile`, có thể xóa các file biên dịch bằng lệnh:
```sh
make clean
```
Nếu biên dịch thủ công, hãy xóa file thực thi:
```sh
rm lexer
```

## Ghi chú
- Hỗ trợ nhận diện toán tử (`+`, `-`, `*`, `/`, `=`, `<>`, `<`, `<=`, `>`, `>=`), dấu câu (`;`, `,`, `.`, `:`) và từ khóa (`VAR`, `IF`, `THEN`, ...).
- Đọc file `.pl0` làm đầu vào, xử lý từng token và in kết quả ra màn hình.

