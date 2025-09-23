#!/bin/bash

# Push Swap Testing Script
# Comprehensive test suite for the Push Swap project

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

PUSH_SWAP="./push_swap"
CHECKER="../push_swap_checker"  # If you have the checker from 42

echo -e "${BLUE}🧪 Push Swap Comprehensive Test Suite${NC}"
echo "========================================"

# Function to test a specific case
test_case() {
    local test_name=$1
    local numbers=$2
    local expected_max_ops=${3:-0}

    echo -e "\n${YELLOW}📋 Testing: $test_name${NC}"
    echo "Numbers: $numbers"

    # Generate instructions
    local instructions=$($PUSH_SWAP $numbers)
    local op_count=$(echo "$instructions" | wc -l)

    echo "Operations: $op_count"
    echo "Instructions:"
    echo "$instructions"

    # Basic validation
    if [ -z "$instructions" ]; then
        echo -e "${RED}❌ No instructions generated${NC}"
        return 1
    fi

    # Check if operations are valid (basic check)
    if echo "$instructions" | grep -q "^\(sa\|sb\|ss\|pa\|pb\|ra\|rb\|rr\|rra\|rrb\|rrr\)*$"; then
        echo -e "${GREEN}✅ Valid operations${NC}"
    else
        echo -e "${RED}❌ Invalid operations detected${NC}"
        echo -e "${RED}❌ Instructions were: $instructions${NC}"
        return 1
    fi

    # Performance check
    if [ $expected_max_ops -gt 0 ] && [ $op_count -le $expected_max_ops ]; then
        echo -e "${GREEN}✅ Operations within expected range${NC}"
    elif [ $expected_max_ops -gt 0 ]; then
        echo -e "${YELLOW}⚠️  Operations exceed expected range (Expected: ≤$expected_max_ops, Got: $op_count)${NC}"
    fi

    return 0
}

# Function to test edge cases
test_edge_cases() {
    echo -e "\n${BLUE}🔍 Testing Edge Cases${NC}"
    echo "===================="

    # Already sorted
    test_case "Already sorted (3 elements)" "1 2 3" 0

    # Reverse sorted
    test_case "Reverse sorted (3 elements)" "3 2 1" 3

    # Single element
    test_case "Single element" "42" 0

    # Two elements
    test_case "Two elements" "2 1" 1

    # Duplicate numbers (should handle error)
    echo -e "\n${YELLOW}📋 Testing duplicate numbers (should fail):${NC}"
    if $PUSH_SWAP 1 2 2 >/dev/null 2>&1; then
        echo -e "${RED}❌ Should have failed with duplicates${NC}"
    else
        echo -e "${GREEN}✅ Correctly rejected duplicates${NC}"
    fi

    # Empty input
    echo -e "\n${YELLOW}📋 Testing empty input:${NC}"
    if $PUSH_SWAP >/dev/null 2>&1; then
        echo -e "${RED}❌ Should have failed with no arguments${NC}"
    else
        echo -e "${GREEN}✅ Correctly rejected empty input${NC}"
    fi
}

# Function to test small cases
test_small_cases() {
    echo -e "\n${BLUE}🔢 Testing Small Cases (3-5 elements)${NC}"
    echo "===================================="

    local test_cases=(
        "3 elements - random:1 3 2:3"
        "3 elements - sorted:1 2 3:0"
        "4 elements:2 1 4 3:5"
        "5 elements:3 1 4 2 5:12"
        "5 elements - reverse:5 4 3 2 1:5"
    )

    for test in "${test_cases[@]}"; do
        IFS=':' read -r name numbers max_ops <<< "$test"
        test_case "$name" "$numbers" "$max_ops"
    done
}

# Function to test medium cases
test_medium_cases() {
    echo -e "\n${BLUE}🔢 Testing Medium Cases (10-100 elements)${NC}"
    echo "=========================================="

    # Test with 10 elements
    echo -e "\n${YELLOW}📋 Testing 10 random elements:${NC}"
    local numbers_10=$(shuf -i 1-100 -n 10 | tr '\n' ' ')
    test_case "10 random elements" "$numbers_10" 50

    # Test with 50 elements
    echo -e "\n${YELLOW}📋 Testing 50 random elements:${NC}"
    local numbers_50=$(shuf -i 1-500 -n 50 | tr '\n' ' ')
    test_case "50 random elements" "$numbers_50" 1000
}

# Function to test large cases
test_large_cases() {
    echo -e "\n${BLUE}🔢 Testing Large Cases (100+ elements)${NC}"
    echo "======================================"

    # Test with 100 elements
    echo -e "\n${YELLOW}📋 Testing 100 random elements:${NC}"
    local numbers_100=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
    test_case "100 random elements" "$numbers_100" 2000

    # Test with 500 elements
    echo -e "\n${YELLOW}📋 Testing 500 random elements:${NC}"
    local numbers_500=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
    test_case "500 random elements" "$numbers_500" 10000
}

# Function to test specific patterns
test_patterns() {
    echo -e "\n${BLUE}🔍 Testing Specific Patterns${NC}"
    echo "============================"

    # Nearly sorted
    test_case "Nearly sorted (5 elements)" "1 2 4 3 5" 3

    # All same digit
    test_case "Same tens digit" "10 11 12 13 14" 8

    # Fibonacci-like
    test_case "Fibonacci pattern" "1 1 2 3 5" 8

    # Alternating high-low
    test_case "High-low pattern" "5 1 4 2 3" 7
}

# Function to run performance benchmark
benchmark() {
    echo -e "\n${BLUE}⚡ Performance Benchmark${NC}"
    echo "========================"

    local sizes=(10 50 100 500)
    local runs=3

    echo "Size | Run 1 | Run 2 | Run 3 | Average"
    echo "-----|-------|-------|-------|--------"

    for size in "${sizes[@]}"; do
        local total_ops=0
        local times=()

        for run in $(seq 1 $runs); do
            local numbers=$(shuf -i 1-$((size*10)) -n $size | tr '\n' ' ')
            local start_time=$(date +%s%N)
            local instructions=$($PUSH_SWAP $numbers 2>/dev/null)
            local end_time=$(date +%s%N)
            local op_count=$(echo "$instructions" | wc -l)

            total_ops=$((total_ops + op_count))
            times+=($op_count)

            # Calculate time in ms
            local time_ms=$(( (end_time - start_time) / 1000000 ))
            echo -e "Time for run $run: ${time_ms}ms"
        done

        local avg_ops=$((total_ops / runs))
        echo -e "${size}"'    '"${times[0]}"'     '"${times[1]}"'     '"${times[2]}"'     '"$avg_ops"
    done
}

# Main execution
main() {
    # Check if push_swap exists
    if [ ! -f "$PUSH_SWAP" ]; then
        echo -e "${RED}❌ Push Swap executable not found. Please compile first.${NC}"
        echo "Run: make"
        exit 1
    fi

    # Make executable
    chmod +x "$PUSH_SWAP"

    # Run all tests
    test_edge_cases
    test_small_cases
    test_medium_cases
    test_large_cases
    test_patterns

    # Ask for benchmark
    echo -e "\n${YELLOW}Run performance benchmark? (y/n):${NC}"
    read -r run_benchmark

    if [[ $run_benchmark == "y" || $run_benchmark == "Y" ]]; then
        benchmark
    fi

    echo -e "\n${GREEN}🎉 Test suite completed!${NC}"
    echo -e "${YELLOW}Note: For more comprehensive testing, consider using the 42 checker.${NC}"
}

# Check if script is run directly
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
