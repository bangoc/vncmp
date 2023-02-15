import vncmp

print(vncmp.wchcmp('a', 'b'))
print(vncmp.wchcmp('b', 'a'))
print(vncmp.wchcmp('c', 'c'))
print(vncmp.wchcmp('a', 'ă'))
print(vncmp.wscmp('Hà Nội', 'Hà Nam'))
print(vncmp.wscmp('Hà Nội', 'Hải Phòng'))
print(vncmp.wscmp('Hà Nội', 'Hưng Yên'))
print(vncmp.wscmp('aaaa', 'aaaabb'))
print(vncmp.wscmp('aaaabb', 'aaa'))
print(vncmp.wscmp('Hà Nội', 'Hà Nội'))