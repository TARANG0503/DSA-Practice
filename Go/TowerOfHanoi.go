package main

import (
	"fmt"
)

func TowerOfHanoi(n int, from_rod byte, to_rod byte, aux_rod byte){
  if n == 0{
    return;
  }

  TowerOfHanoi(n-1, from_rod, aux_rod, to_rod)
  fmt.Printf("move disk %d from rod %c to rod %c\n", n, from_rod, to_rod)

  TowerOfHanoi(n-1, aux_rod, to_rod, from_rod)

}

func main() {
   TowerOfHanoi(3, 'A', 'B', 'C')
}
