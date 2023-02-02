Trong triển khai này tôi đã thực hiện ánh xạ mã số của các ký tự 
có dấu  tiếng Việt để tạo thành dãy liên tục với ký tự gốc 
của nó.

2 phương pháp đã được triển khai:

1) Ánh xạ mã số của các ký tự sang miền số thực, trong đó dịch chuyển các 
ký tự tiếng Việt cần thiết và giữ nguyên mã số của các ký tự còn lại.
Ví dụ: ánh xạ mã số của À thành 65.01 để nằm giữa A và B.

2) Ánh xạ mã số của các ký tự sang 1 hoán vị của các mã số Unicode trong miền 
ký tự tiếng Việt.
Theo cách này mã số của B, C, D, ... được dịch sang phải để tạo chỗ trống cho các ký tự có gốc A: À, Ã, Ả, v...
Phương pháp 2 đang được triển khai trong phiên bản hiện tại do có tiềm năng cao hơn về hiệu năng.

Sau khi ánh xạ các chuỗi được so sánh theo từng ký tự giống như giải thuật
so sánh chuỗi chuẩn. Ánh xạ về cơ bản làm thay đổi quan hệ thứ tự giữa các ký tự để phù hợp với bảng chữ cái tiếng Việt.

Các mã số được xác định theo TCVN 6909:2001
