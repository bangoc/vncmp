package main

import (
	"fmt"
	"github.com/bangoc/vncmp"
)

func main() {
	fmt.Print(vncmp.Wchcmp('a', 'b'), "\n")
	fmt.Print(vncmp.Wchcmp('a', 'a'), "\n")
	fmt.Print(vncmp.Wchcmp('c', 'b'), "\n")
	fmt.Print(vncmp.Wscmp("aa", "aabb"), "\n")
	fmt.Print(vncmp.Wscmp("aabb", "aab"), "\n")
	fmt.Print(vncmp.Wscmp("aabb", "aabb"), "\n")
	fmt.Print(vncmp.Wscmp("Hà Nội", "Hà Nam"), "\n")
	fmt.Print(vncmp.Wscmp("Ha Noi", "Hà Nam"), "\n")
	fmt.Print(vncmp.Wscmp("Hưng Yên", "Hưng Hóa"), "\n")
	fmt.Print(vncmp.Wscmp("Hà Nội", "Hà Nội"), "\n")
}