\c company

select fname, lname,
salary, 1.1*salary as newSalary
from employee e, works_on w, project p
where e.ssn = w.essn and w.pno = p.pnumber
and p.pname='ProductX';

select SUM(salary) as sumSalary,AVG(salary) as avgSalary,MIN(salary) as minSalary,MAX(salary) as maxSalary from employee e, department d where e.dno = d.dnumber and d.dname = 'Research';

select count(DISTINCT salary) from employee;

select lname, fname from employee where (select count(*) from dependent where ssn = essn)>=2;

select dno, count(*), avg(salary) from employee group by dno;

select fname, lname from employee where salary >= (10000 + (select MIN(salary) from employee));

select fname, lname from employee where (dno = (select dno from employee where salary = (select max(salary) from employee)));

select dno, count(*) from employee where salary > 40000 group by dno;
