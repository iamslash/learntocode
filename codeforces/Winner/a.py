n = int(input())
d_score = dict()
d = []
for i in range(n):
    name, score = input().split()
    d_score[name] = d_score.get(name, 0) + int(score)
    d.append((name, + int(score)))
#print(d)
max_score = max(d_score.values())
max_name = []
for k, v in d_score.items():
    if max_score == v:
        max_name.append(k)

if len(max_name) == 1:
    print(max_name[0])
else:
    for el in d:
        if el[0] in max_name:
            d_score[el[0]] -= el[1]
            if d_score[el[0]] <= 0:
                print(el[0])
                break
