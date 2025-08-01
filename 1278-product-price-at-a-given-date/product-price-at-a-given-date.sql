# Write your MySQL query statement below
WITH LastPrice AS (
    SELECT
        product_id,
        new_price
    FROM
        (
            SELECT
                product_id,
                new_price,
                RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) as rnk
            FROM
                Products
            WHERE
                change_date <= '2019-08-16'
        ) AS RankedPrices
    WHERE
        rnk = 1
)

SELECT
    p.product_id,
    COALESCE(lp.new_price, 10) AS price
FROM
    (SELECT DISTINCT product_id FROM Products) AS p
LEFT JOIN
    LastPrice AS lp ON p.product_id = lp.product_id;