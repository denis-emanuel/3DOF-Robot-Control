syms q1 q2 q3 Px Py Pz
syms a b c x y z

q3=atan((Pz/2-7-3*sin(q2))/(Py/2/cos(q1)-3*cos(q2)))

solve((Pz/2-7)==(sin(q2+q3)+3*sin(q2)), q2);

eqns = [(2*cos(q1)*(cos(q2+q3)+3*cos(q2))) == Py, (2*sin(q2+q3)+3*sin(q2)) == 0];
S = solve(eqns,[q2 q3])

%%
eqn = sin(b+c)+3*sin(b) == z/2-7;
sol = solve(eqn, b)

eqn2 = 2 * cos(a) * ( cos(b+c) + 3*cos(b) )
sol = solve(eqn, b)

%%
syms q1 q2 q3 Py Pz
Result=solve(2*cos(q1)*(cos(q2-q3)+3*cos(q2))==Py,...
  -2*sin(q2-q3)-6*sin(q2)+14==14,q2,q3);
simplify(Result.q2,'Steps',100)
simplify(Result.q3,'Steps',100)

%%
syms q1 q2 q3 Py Pz 
eqns = [Py==2*cos(q1) * (cos(q2+q3) + 3*cos(q2)), Pz==2*sin(q2+q3) +6*sin(q2) + 14] 
vars = [q2 q3] 
result = solve(eqns,vars) 
q2 = simplify(result.q2) 
q3 = simplify(result.q3) 

param=3;
q2=subs(q2,parameters,param)