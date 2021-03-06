/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <memory>
#include <optional>

#include "common/unit_test_util/unit_test_util.h"
#include "gomoku/agent/heuristics/light_rollout_evaluator.h"
#include "gomoku/game/board_state.h"

bool RewardEvaluationTest() {
    e8::GomokuBoardState board(/*width=*/7, /*height=*/7);

    // Player A will very likely win in this case whereas Player B will lose.
    // - - - - - - o
    // - - - - - - -
    // - - x - o - -
    // - - - x - - -
    // - - - - x - -
    // - - - - - - -
    // - - - - - - -
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/2, /*y=*/2)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/3, /*y=*/3)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/4, /*y=*/2)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.Swap2DecisionToActionId(e8::Swap2Decision::SW2D_CHOOSE_WHITE),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/6, /*y=*/0)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/4, /*y=*/4)),
                      /*cached_game_result=*/std::nullopt);

    e8::GomokuLightRolloutEvaluator evaluator;
    float player_b_reward =
        evaluator.EvaluateReward(board, /*parent_state_id=*/std::nullopt, /*state_id=*/3);
    TEST_CONDITION(player_b_reward < 0);

    // - - - - - - o
    // - - - - - o -
    // - - x - o - -
    // - - - x - - -
    // - - - - x - -
    // - - - - - - -
    // - - - - - - -
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/5, /*y=*/1)),
                      /*cached_game_result=*/std::nullopt);

    float player_a_reward =
        evaluator.EvaluateReward(board, /*parent_state_id=*/std::nullopt, /*state_id=*/4);
    TEST_CONDITION(player_a_reward > 0);

    // Using the cache should give the same result.
    float player_a_reward_cached =
        evaluator.EvaluateReward(board, /*parent_state_id=*/std::nullopt, /*state_id=*/4);
    TEST_CONDITION(player_a_reward_cached == player_a_reward);

    return true;
}

bool RewardEvaluationTest2() {
    // Player B will very likely win in this case whereas Player B will lose.
    // - - - - - - - - - - -
    // - - - - - - - - - - -
    // - - - - - - - - - - -
    // - - - - x - - - - - -
    // - - - - - - - - - - -
    // - - - - - - - - - - -
    // - - - x - - - - - o -
    // - - - - - - - - - o -
    // - - - - - - - - - - -
    // - - - - - - - - - - -
    // - - - - - x - - - - -
    e8::GomokuBoardState board(/*width=*/11, /*height=*/11);
    e8::GomokuActionId action_id = board.MovePositionToActionId(e8::MovePosition(/*x=*/3, /*y=*/6));
    board.ApplyAction(action_id, /*cached_game_result=*/std::nullopt);

    action_id = board.MovePositionToActionId(e8::MovePosition(/*x=*/4, /*y=*/3));
    board.ApplyAction(action_id, /*cached_game_result=*/std::nullopt);

    action_id = board.MovePositionToActionId(e8::MovePosition(/*x=*/9, /*y=*/7));
    board.ApplyAction(action_id, /*cached_game_result=*/std::nullopt);

    action_id = board.Swap2DecisionToActionId(e8::Swap2Decision::SW2D_CHOOSE_WHITE);
    board.ApplyAction(action_id, /*cached_game_result=*/std::nullopt);

    action_id = board.MovePositionToActionId(e8::MovePosition(/*x=*/9, /*y=*/6));
    board.ApplyAction(action_id, /*cached_game_result=*/std::nullopt);

    action_id = board.MovePositionToActionId(e8::MovePosition(/*x=*/5, /*y=*/10));
    board.ApplyAction(action_id, /*cached_game_result=*/std::nullopt);

    e8::GomokuLightRolloutEvaluator evaluator;
    float player_b_reward =
        evaluator.EvaluateReward(board, /*parent_state_id=*/std::nullopt, /*state_id=*/3);
    TEST_CONDITION(player_b_reward > 0);

    return true;
}

bool PolicyEvaluationTest() {
    e8::GomokuBoardState board(/*width=*/7, /*height=*/7);

    // - - - - - - o
    // - - - - - - -
    // - - x - o - -
    // - - - x - - -
    // - - - - x - -
    // - - - - - - -
    // - - - - - - -
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/2, /*y=*/2)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/3, /*y=*/3)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/4, /*y=*/2)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.Swap2DecisionToActionId(e8::Swap2Decision::SW2D_CHOOSE_WHITE),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/6, /*y=*/0)),
                      /*cached_game_result=*/std::nullopt);
    board.ApplyAction(board.MovePositionToActionId(e8::MovePosition(/*x=*/4, /*y=*/4)),
                      /*cached_game_result=*/std::nullopt);

    e8::GomokuLightRolloutEvaluator evaluator;
    std::unordered_map<e8::GomokuActionId, float> policy =
        evaluator.EvaluatePolicy(board, /*parent_state_id=*/std::nullopt, /*state_id=*/2);

    // Contour
    // - - - - - ? o
    // - ? ? ? ? ? ?
    // - ? x ? o ? -
    // - ? ? x ? ? -
    // - - ? ? x ? -
    // - - - ? ? ? -
    // - - - - - - -
    TEST_CONDITION(policy.size() == 7 * 7 - 5);
    unsigned num_zero = 0;
    unsigned num_nonzero = 0;
    for (auto const &[action_id, p] : policy) {
        if (p == 0) {
            ++num_zero;
        } else {
            TEST_CONDITION(p == 1.0f / 20.0f);
            ++num_nonzero;
        }
    }

    TEST_CONDITION(num_zero == 24);
    TEST_CONDITION(num_nonzero == 20);

    return true;
}

int main() {
    e8::BeginTestSuite("light_rollout_evaluator");
    e8::RunTest("RewardEvaluationTest", RewardEvaluationTest);
    e8::RunTest("RewardEvaluationTest2", RewardEvaluationTest2);
    e8::RunTest("PolicyEvaluationTest", PolicyEvaluationTest);
    e8::EndTestSuite();
    return 0;
}
