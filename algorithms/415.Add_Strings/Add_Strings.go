package problem415

func addStrings(s1, s2 string) string {
	// 确保 n1 <= n2
	if len(s1) > len(s2) {
		s1, s2 = s2, s1
	}

	carry := byte(0)
	result := ""

	for len(s1) > 0 || len(s2) > 0 {
		val := carry

		if len(s1) > 0 {
			s1Pop := s1[len(s1)-1] - byte('0')
			s1 = s1[:len(s1)-1]
			val = val + s1Pop
		}

		if len(s2) > 0 {
			s2Pop := s2[len(s2)-1] - byte('0')
			s2 = s2[:len(s2)-1]
			val = val + s2Pop
		}

		carry = val / 10
		n := val % 10
		result = string(n+'0') + result
	}

	if carry > 0 {
		result = string(carry+'0') + result
	}
	return result

}

func main() {

}
