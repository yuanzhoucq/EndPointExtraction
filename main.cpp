#include <vector>
#include <string>
#include "extractEndPoints.cpp"

int main() {
    std::vector<std::string> files{"2470.png", "2316.png", "2074.png", "2289.png", "2302.png", "2464.png", "2458.png",
                                   "2114.png", "2100.png","2128.png", "2060.png", "2048.png", "2504.png", "2262.png",
                                   "2276.png", "2510.png", "2538.png", "2539.png", "2277.png", "2511.png", "2505.png",
                                   "2263.png", "2288.png", "2049.png", "2075.png", "2061.png", "2129.png", "2101.png",
                                   "2115.png", "2459.png", "2303.png", "2465.png", "2471.png", "2317.png", "2498.png",
                                   "2467.png", "2301.png", "2315.png", "2473.png", "2329.png", "2103.png", "2117.png",
                                   "2088.png", "2077.png", "2063.png", "2513.png", "2275.png", "2261.png", "2507.png",
                                   "2249.png", "1998.png", "1999.png", "2248.png", "2260.png", "2506.png", "2512.png",
                                   "2274.png", "2062.png", "2076.png", "2089.png", "2116.png", "2102.png", "2328.png",
                                   "2314.png", "2472.png", "2466.png", "2300.png", "2499.png", "2489.png", "2338.png",
                                   "2304.png", "2462.png", "2476.png", "2310.png", "2106.png", "2112.png", "2099.png",
                                   "2072.png", "2066.png", "1989.png", "2258.png", "2270.png", "2516.png", "2502.png",
                                   "2264.png", "2503.png", "2265.png", "2271.png", "2517.png", "2259.png", "1988.png",
                                   "2067.png", "2073.png", "2098.png", "2113.png", "2107.png", "2477.png", "2311.png",
                                   "2305.png", "2463.png", "2339.png", "2488.png", "2449.png", "2313.png", "2475.png",
                                   "2461.png", "2307.png", "2139.png", "2111.png", "2105.png", "2059.png", "2065.png",
                                   "2071.png", "2298.png", "2529.png", "2267.png", "2501.png", "2515.png", "2273.png",
                                   "2514.png", "2272.png", "2266.png", "2500.png", "2528.png", "2299.png", "2070.png",
                                   "2064.png", "2058.png", "2104.png", "2110.png", "2138.png", "2460.png", "2306.png",
                                   "2312.png", "2474.png", "2448.png", "2375.png", "2413.png", "2407.png", "2361.png",
                                   "2349.png", "2188.png", "2177.png", "2163.png", "2003.png", "2017.png", "2201.png",
                                   "2215.png", "2229.png", "2228.png", "2214.png", "2200.png", "2016.png", "2002.png",
                                   "2162.png", "2176.png", "2189.png", "2348.png", "2406.png", "2360.png", "2374.png",
                                   "2412.png", "2389.png", "2362.png", "2404.png", "2410.png", "2376.png", "2438.png",
                                   "2160.png", "2174.png", "2148.png", "2014.png", "2000.png", "2028.png", "2216.png",
                                   "2564.png", "2202.png", "2558.png", "2559.png", "2203.png", "2217.png", "2029.png",
                                   "2001.png", "2015.png", "2149.png", "2175.png", "2161.png", "2439.png", "2411.png",
                                   "2377.png", "2363.png", "2405.png", "2388.png", "2398.png", "2429.png", "2401.png",
                                   "2367.png", "2373.png", "2415.png", "2159.png", "2165.png", "2171.png", "2039.png",
                                   "2011.png", "2005.png", "2549.png", "2213.png", "2207.png", "2561.png", "2206.png",
                                   "2560.png", "2212.png", "2548.png", "2004.png", "2010.png", "2038.png", "2170.png",
                                   "2164.png", "2158.png", "2372.png", "2414.png", "2400.png", "2366.png", "2428.png",
                                   "2399.png", "2358.png", "2416.png", "2370.png", "2364.png", "2402.png", "2199.png",
                                   "2172.png", "2166.png", "2006.png", "2012.png", "2238.png", "2562.png", "2204.png",
                                   "2210.png", "2211.png", "2563.png", "2205.png", "2239.png", "2013.png", "2007.png",
                                   "2167.png", "2173.png", "2198.png", "2365.png", "2403.png", "2417.png", "2371.png",
                                   "2359.png", "2397.png", "2383.png", "2354.png", "2432.png", "2426.png", "2340.png",
                                   "2368.png", "2195.png", "2181.png", "2156.png", "2142.png", "2022.png", "2036.png",
                                   "2220.png", "2546.png", "2552.png", "2234.png", "2208.png", "2209.png", "2553.png",
                                   "2235.png", "2221.png", "2547.png", "2037.png", "2023.png", "2143.png", "2157.png",
                                   "2180.png", "2194.png", "2369.png", "2427.png", "2341.png", "2355.png", "2433.png",
                                   "2382.png", "2396.png", "2380.png", "2394.png", "2343.png", "2425.png", "2431.png",
                                   "2357.png", "2419.png", "2182.png", "2196.png", "2141.png", "2155.png", "2169.png",
                                   "2035.png", "2021.png", "2009.png", "2237.png", "2551.png", "2545.png", "2223.png",
                                   "2544.png", "2222.png", "2236.png", "2550.png", "2008.png", "2020.png", "2034.png",
                                   "2168.png", "2154.png", "2140.png", "2197.png", "2183.png", "2418.png", "2430.png",
                                   "2356.png", "2342.png", "2424.png", "2395.png", "2381.png", "2385.png", "2391.png",
                                   "2408.png", "2420.png", "2346.png", "2352.png", "2434.png", "2187.png", "2193.png",
                                   "2178.png", "2144.png", "2150.png", "2018.png", "2030.png", "2024.png", "2554.png",
                                   "2232.png", "2226.png", "2540.png", "2227.png", "2541.png", "2555.png", "2233.png",
                                   "2025.png", "2031.png", "2019.png", "2151.png", "2145.png", "2179.png", "2192.png",
                                   "2186.png", "2353.png", "2435.png", "2421.png", "2347.png", "2409.png", "2390.png",
                                   "2384.png", "2392.png", "2386.png", "2379.png", "2437.png", "2351.png", "2345.png",
                                   "2423.png", "2190.png", "2184.png", "2153.png", "2147.png", "2027.png", "2033.png",
                                   "2219.png", "2543.png", "2225.png", "2231.png", "2557.png", "2230.png", "2556.png",
                                   "2542.png", "2224.png", "2218.png", "2032.png", "2026.png", "2146.png", "2152.png",
                                   "2185.png", "2191.png", "2344.png", "2422.png", "2436.png", "2350.png", "2378.png",
                                   "2387.png", "2393.png", "2492.png", "2486.png", "2451.png", "2337.png", "2323.png",
                                   "2445.png", "2479.png", "2135.png", "2121.png", "2109.png", "2082.png", "2096.png",
                                   "2041.png", "2055.png", "2069.png", "2280.png", "2294.png", "1979.png", "2525.png",
                                   "1992.png", "2243.png", "2257.png", "1986.png", "2531.png", "2519.png", "2518.png",
                                   "1987.png", "2256.png", "2530.png", "2524.png", "2242.png", "1993.png", "1978.png",
                                   "2295.png", "2281.png", "2068.png", "2054.png", "2040.png", "2097.png", "2083.png",
                                   "2108.png", "2120.png", "2134.png", "2478.png", "2322.png", "2444.png", "2450.png",
                                   "2336.png", "2487.png", "2493.png", "2485.png", "2491.png", "2446.png", "2320.png",
                                   "2334.png", "2452.png", "2308.png", "2122.png", "2136.png", "2095.png", "2081.png",
                                   "2056.png", "2042.png", "2297.png", "2283.png", "2532.png", "2254.png", "1985.png",
                                   "1991.png", "2240.png", "2526.png", "2268.png", "2269.png", "2241.png", "1990.png",
                                   "2527.png", "2533.png", "1984.png", "2255.png", "2282.png", "2296.png", "2043.png",
                                   "2057.png", "2080.png", "2094.png", "2137.png", "2123.png", "2309.png", "2335.png",
                                   "2453.png", "2447.png", "2321.png", "2490.png", "2484.png", "2480.png", "2494.png",
                                   "2319.png", "2325.png", "2443.png", "2457.png", "2331.png", "2127.png", "2133.png",
                                   "2090.png", "2084.png", "2053.png", "2047.png", "2292.png", "2286.png", "2279.png",
                                   "2251.png", "1980.png", "2537.png", "2523.png", "1994.png", "2245.png", "2522.png",
                                   "2244.png", "1995.png", "1981.png", "2250.png", "2536.png", "2278.png", "2287.png",
                                   "2293.png", "2046.png", "2052.png", "2085.png", "2091.png", "2132.png", "2126.png",
                                   "2456.png", "2330.png", "2324.png", "2442.png", "2318.png", "2495.png", "2481.png",
                                   "2497.png", "2483.png", "2468.png", "2332.png", "2454.png", "2440.png", "2326.png",
                                   "2118.png", "2130.png", "2124.png", "2087.png", "2093.png", "2078.png", "2044.png",
                                   "2050.png", "2285.png", "2291.png", "2508.png", "1997.png", "2246.png", "2520.png",
                                   "2534.png", "2252.png", "1983.png", "2535.png", "1982.png", "2253.png", "2247.png",
                                   "1996.png", "2521.png", "2509.png", "2290.png", "2284.png", "2051.png", "2045.png",
                                   "2079.png", "2092.png", "2086.png", "2125.png", "2131.png", "2119.png", "2441.png",
                                   "2327.png", "2333.png", "2455.png", "2469.png", "2482.png", "2496.png"};
    for (const auto &file: files) {
        bool debug = true;
        std::string home = std::getenv("HOME");
        cv::Mat img = cv::imread(home + "/Downloads/Ims/有干扰~12ms/" + file, cv::IMREAD_GRAYSCALE);

        std::vector<cv::Point> endPoints;
        extractEndPoints(img, endPoints, 4, 5, 200, debug);

        if (debug) {
            for (auto &p: endPoints) {
                cv::circle(img, p, 10, 255);
            }
            imshow(img, file);
        }
    }
    return 0;
}
