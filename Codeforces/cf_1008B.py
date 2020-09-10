def solve(n, data):
	assert(len(data) == n)
	IsThereSolution = True
	last_height = max(data[0][0], data[0][1])
	
	for i in range(1, n):
		if(data[i][1] <= last_height): 
			last_height = data[i][1]
		elif(data[i][0] <= last_height):
			last_height = data[i][0]
		else: 
			IsThereSolution = False
			break
	
	return IsThereSolution		
		

def main(): 
	n = int(input())
	rect = [] 
	for i in range(n): 
		h, w = map(int, input().split())
		if(h > w): h, w = w, h
		rect.append([h, w])

	answer = solve(n, rect)
	if(answer): 
		print("YES")
	else: 
		print("NO")

main()
