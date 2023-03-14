-- In 7.sql, write a SQL query that returns the average energy of songs that are by Drake.

-- Your query should output a table with a single column and a single row containing the average energy.

-- SELECT AVG(songs.energy)
-- FROM songs JOIN artists
-- ON songs.id=artists.id
-- WHERE artists.name = 'Drake';

SELECT AVG(songs.energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');