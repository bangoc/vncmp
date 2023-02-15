package main

import (
	"fmt"
	"github.com/bangoc/vncmp"
)

func main() {
	fmt.Print(vncmp.Wchcmp('a', 'b'), "\n")
	fmt.Print(vncmp.Wchcmp('a', 'a'), "\n")
	fmt.Print(vncmp.Wchcmp('c', 'b'), "\n")
	fmt.Print(vncmp.U8scmp("aa", "aabb"), "\n")
	fmt.Print(vncmp.U8scmp("aabb", "aab"), "\n")
	fmt.Print(vncmp.U8scmp("aabb", "aabb"), "\n")
	fmt.Print(vncmp.U8scmp("Hà Nội", "Hà Nam"), "\n")
	fmt.Print(vncmp.U8scmp("Ha Noi", "Hà Nam"), "\n")
	fmt.Print(vncmp.U8scmp("Hưng Yên", "Hưng Hóa"), "\n")
	fmt.Print(vncmp.U8scmp("Hà Nội", "Hà Nội"), "\n")
}