/* Write your PL/SQL query statement below */
select score,
    (select count(distinct score)
    from scores b
    where b.score>=a.score) as Rank
    from scores a
    order by Rank;
    
