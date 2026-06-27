impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut end = nums.len() as i32 - 1;

        for idx in (0.. nums.len() as i32 - 1).rev() {      
            if idx + nums[idx as usize] >= end {
                end = idx;
            }
        }
        
        end == 0
    }
}
