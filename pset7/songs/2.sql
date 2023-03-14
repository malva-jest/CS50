-- In 2.sql, write a SQL query to list the names of all songs in increasing order of tempo.

-- Your query should output a table with a single column for the name of each song.

SELECT name AS Song_Title FROM songs ORDER BY tempo;
-- could say ASC if you wish but there's a default