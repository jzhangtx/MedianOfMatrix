package main

import "fmt"

func Merge(v1 []int, v2 []int) []int {
	v := make([]int, len(v1)+len(v2))
	index := 0
	i := 0
	j := 0
	for i < len(v1) && j < len(v2) {
		if v1[i] < v2[j] {
			v[index] = v1[i]
			index++
			i++
		} else {
			v[index] = v2[j]
			index++
			j++
		}
	}

	for i < len(v1) {
		v[index] = v1[i]
		index++
		i++
	}

	for j < len(v2) {
		v[index] = v2[j]
		index++
		j++
	}

	return v
}

func CalculateMedianOfMatrix(matrix [][]int) int {
	vec := matrix[0]
	for i := 1; i < len(matrix); i++ {
		vec = Merge(vec, matrix[i])
	}

	fmt.Println(vec)
	return vec[len(vec)/2]
}

func main() {
	for {
		fmt.Print("The size of the matrix (rows, colomns): ")
		var rows, cols int
		fmt.Scan(&rows, &cols)
		if rows == 0 && cols == 0 {
			break
		}

		matrix := make([][]int, rows)
		for i := 0; i < rows; i++ {
			matrix[i] = make([]int, cols)
			fmt.Printf("The %dth row: ", i)
			for j := 0; j < cols; j++ {
				fmt.Scan(&matrix[i][j])
			}
		}

		median := CalculateMedianOfMatrix(matrix)
		fmt.Printf("The median of the matrix is %d\n", median)
	}
}
