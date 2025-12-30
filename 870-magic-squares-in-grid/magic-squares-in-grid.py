class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def check(row,col):
            # print(row,col)
            diff=set()
            diagonal_sum=0
            diagonal_sum=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]

            arr=[]
            arr.append(diagonal_sum)
            for i in range(row,row+3):
                row_sum=0
                for j in range(col,col+3):
                    row_sum+=grid[i][j]
                    if grid[i][j]>=1 and grid[i][j]<=9:
                        diff.add(grid[i][j])
                    else:
                        return False
                arr.append(row_sum)
            arr.append(diagonal_sum)
            for j in range(col,col+3):
                col_sum=0
                for i in range(row,row+3):
                    col_sum+=grid[i][j]
                arr.append(col_sum)
            d=0
            d+=grid[row+2][col]
            d+=grid[row][col+2]
            d+=grid[row+1][col+1]
            arr.append(d)
            arr.sort()
            return arr[0]==arr[-1] and len(diff)==9
        
        n,m=len(grid),len(grid[0])
        cnt=0
        for i in range(n-2):
            for j in range(m-2):
                if check(i,j):
                    cnt+=1
        return cnt
        