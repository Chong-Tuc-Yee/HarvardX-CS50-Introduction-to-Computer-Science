SELECT DISTINCT name  -- We only need to mention once for people who starred in any movies in same year.
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE year = 2004
ORDER BY birth;

-- Write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
-- People with the same birth year may be listed in any order.
-- No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
-- If a person appeared in more than one movie in 2004, they should only appear in your results once.
