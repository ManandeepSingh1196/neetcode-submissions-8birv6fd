impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut reach = 0;

        for (i, &jump) in nums.iter().enumerate() {
            if i > reach {
                return false;
            }
            reach = reach.max(i + jump as usize);
        }

        true
    }
}