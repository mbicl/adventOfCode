import numpy
from scipy.optimize import LinearConstraint, milp


def solve(vc, joltages):
    c = []
    for v in vc:
        c.append(1)
    c = numpy.array(c)

    x = []
    for j_index in range(0, len(joltages)):
        f = []
        for v in vc:
            f.append(1 if j_index in v else 0)
        x.append(f)
    a = numpy.array(x)

    ub = numpy.array(joltages)
    lb = ub

    constraints = LinearConstraint(A=a, lb=lb, ub=ub)
    integrality = numpy.ones_like(c)
    res = milp(c=c, constraints=constraints, integrality=integrality)
    return int(res.fun)


def trimm(s):
    return s[1 : len(s) - 1]


ans = 0

file = open("input.txt", "r")
for line in file:
    line = line.replace("\n", "")
    v = line.split(" ")
    v.pop(0)
    j = trimm(v.pop())
    joltages = []
    for i in j.split(","):
        joltages.append(int(i))
    vc = []
    for i in v:
        s = trimm(i)
        l = []
        for num_str in s.split(","):
            l.append(int(num_str))
        vc.append(l)
    ans += solve(vc, joltages)

print(ans)
