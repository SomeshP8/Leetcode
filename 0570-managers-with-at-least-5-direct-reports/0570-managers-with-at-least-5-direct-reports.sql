SELECT e.name
FROM Employee AS e 
INNER JOIN Employee AS m ON e.id = m.managerId 
GROUP BY m.managerId 
HAVING COUNT(m.managerId) >= 5


-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna