import numpy as np
import heapq 
global num_users, num_items 
name_users = [] 
name_items = []
def nhap():
    print("Nhập các giá trị rating vào, dùng dấu '?' cho các giá trị còn thiếu")
    global num_users 
    num_users = int(input("Nhập số lượng người dùng: "))
    for i in range(num_users):
        tmp = input("Tên người dùng thứ " + str(i + 1) + ": ")
        name_users.append(tmp)
        
    global num_items 
    num_items = int(input("Nhập số lượng sản phẩm: "))

    for i in range(num_items):
        tmp = input("Tên sản phẩm thứ " + str(i + 1) + ": ")
        name_items.append(tmp)
    R = []
    for i in range(num_users):
        row = []
        for j in range(num_items):
            value = input(f"Nhập rating của {name_users[i]} đối với sản phẩm {name_items[j]}: ")
            if value == '?': row.append(np.nan)
            else:
                row.append(float(value))
        R.append(row)
    return np.array(R)
def fillNanValue(A):
    global num_items
    global num_users
    ans = A.copy()
    tmp = A.copy()
    for i in range(num_users):
        cntDifNanRow = 0
        curSumRow = 0
        for l in range(num_items):
            # if tmp[i,l] != nan:
            if not np.isnan(tmp[i,l]):
                cntDifNanRow+=1
                curSumRow+=tmp[i,l]
        for j in range(num_items):
            # if tmp[i,j] == nan:
            if np.isnan(tmp[i,j]):
                curSumCol = 0
                cntDifNanCol = 0
                for k in range(num_users):
                    # if tmp[k,j] != np.nan:
                    if not np.isnan(tmp[k,j]):
                        cntDifNanCol+=1
                        curSumCol += tmp[k,j]
                if cntDifNanCol + cntDifNanRow != 0:
                    ans[i,j] = (curSumCol+curSumRow*0)/(cntDifNanRow*0+cntDifNanCol) # tang trong so cua items[j]
                else: ans[i,j] = 0
    return ans

def svd_Recomendation(A):
    tmp = fillNanValue(A)
    U,S,VT = np.linalg.svd(tmp,full_matrices=False)
    k = min(num_items,num_users) - 1
    U_2 = U[:,:k]
    S_2 = np.diag(S[:k]) 
    VT_2 = VT[:k,:] 
    A_reconstructed = np.dot(U_2,np.dot(S_2,VT_2))
    return A_reconstructed

def printAns(A,A_reconstructed):
    print("Ma trận ban đầu:")
    print(A)
    print()
    print("Ma trận sau sau khi thực hiện phân tích SVD:")
    print(A_reconstructed)
    print()
    
    for i in range(A_reconstructed.shape[0]):
        print(f"Đối với {name_users[i]}, thứ tự gợi ý mua hàng theo chiều giảm dần là: ")
        print()
        
        pq = []
        for j in range(A_reconstructed.shape[1]):
            heapq.heappush(pq,(-1*A_reconstructed[i][j],j))
        cnt = 1
        while pq:
            value, index = heapq.heappop(pq)
            print(f"    {cnt}: {name_items[index]} với rating {round(-1*value,2)}")
            print()
            cnt = cnt + 1
    

def solve():
    
    
    A = nhap()
    A_reconstructed = svd_Recomendation(A)
    printAns(A,A_reconstructed)


def main():
    solve()



if __name__ == "__main__":
    main()