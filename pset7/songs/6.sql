-- In 6.sql, write a SQL query that lists the names of songs that are by Post Malone.

-- Your query should output a table with a single column for the name of each song.
-- You should not make any assumptions about what Post Malone’s artist_id is.

-- SELECT songs.name, artists.name
-- FROM songs JOIN artists
-- ON songs.id=artists.id
-- WHERE artists.name = 'Post Malone';

SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');

-- SELECT songs.name FROM songs LEFT JOIN artists ON songs.id = artists.id
-- WHERE artists.name = 'Post Malone'
-- UNION
-- SELECT artists.name FROM artists LEFT JOIN songs ON artists.id = songs.id
-- WHERE artists.name = 'Post Malone';