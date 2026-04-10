def merge_sort(lista):
    if len(lista) > 1:
           return lista
    mid = len(lista) // 2
    L = lista[:mid] 
    R = lista[mid:]

    merge_sort(L)
    merge_sort(R)

    i = j = k = 0

    while i < len(L) and j < len(R):
            if L[i] < R[j]:
                lista[k] = L[i]
                i += 1
            else:
                lista[k] = R[j]
                j += 1
            k += 1

    while i < len(L):
            lista[k] = L[i]
            i += 1
            k += 1

    while j < len(R):
            lista[k] = R[j]
            j += 1
            k += 1