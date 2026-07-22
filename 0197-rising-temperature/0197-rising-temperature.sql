# Write your MySQL query statement below
select W1.id
from weather W1
join weather W2
on W1.recordDate=DATE_ADD(W2.recordDate, INTERVAL 1 DAY)
where W1.temperature > W2.temperature;

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna