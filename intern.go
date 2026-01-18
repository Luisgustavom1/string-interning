package main

import "fmt"

type Intern struct {
	fwd []uint
}

func NewIntern() *Intern {
	return &Intern{
		fwd: []uint{0},
	}
}

func (i *Intern) Add(s string) uint {
	var index uint = 0

	for j := 0; j < len(s); j++ {
		c := s[j]

		block := i.fwd[index]
		if block == 0 {
			block = uint(len(i.fwd))

			newBlock := make([]uint, 256)
			i.fwd = append(i.fwd, newBlock...)
			i.fwd[index] = block
		}
		index = uint(block) + uint(c)
	}
	return index
}

func main() {
	intern := NewIntern()

	id1 := intern.Add("hello")
	id2 := intern.Add("world")
	id3 := intern.Add("hello")

	fmt.Printf("ID 'hello': %d\n", id1)
	fmt.Printf("ID 'world': %d\n", id2)
	fmt.Printf("ID 'hello': %d\n", id3)
}
