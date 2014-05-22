let rec a13 a1 =
  match a1 with
  | [] -> []
  | [_] -> raise Not_found
  | a12 :: a4 :: tl -> (a4, a12) :: a13 tl
    in
    let rec a14 a1 =
      match a1 with
      | [] -> []
      | hd :: tl -> if List.mem hd tl
                    then a14 tl
                    else hd :: a14 tl
    in
    let rec a15 a5 a7 a2 =
      match a7 with
      | [] -> a2
      | (a12,a4) :: tl -> if a12 = a5
                          then a15 a5 tl (a2 + 1)
                          else a15 a5 tl a2
    in
    let rec a16 a3 a7 a8 =
      match a8 with
      | [] -> []
      | hd :: tl -> if a15 hd a7 0 = a3
                    then hd :: a16 a3 a7 tl
                    else a16 a3 a7 tl
    in
    let a17 a8 =
      List.sort (fun a12 a4 -> compare a12 a4) a8
    in
    let rec a18 a5 a7 =
      match a7 with
      | [] -> []
      | (a12,a4) :: tl -> if a12 = a5
                          then a4 :: a18 a5 tl
                          else a18 a5 tl
    in
    let rec a19 a5 a7 =
      match a7 with
      | [] -> []
      | (a12,a4) :: tl -> if a4 = a5
                          then a12 :: a19 a5 tl
                          else a19 a5 tl
    in
    let rec a20 a6 a7 =
      match a7 with
      | [] -> true
      | hd :: tl -> if List.mem hd a6
                    then a20 a6 tl
                    else false
    in
    let rec a21 a7 a8 a9 a10 =
      match a9 with
      | [] -> []
      | hd :: tl -> begin
                    let a11 =
                      a17 (tl @ List.filter (fun a12 ->
                                             a20 (a10 @ [hd]) (a18 a12 a7))
                                            (a19 hd a7))
                    in
                    hd :: (a21 a7 a8 a11 (a10 @ [hd]))
                  end
    in
    let a1 = ref [] in
    try
      while true do
        a1 := (read_line ()) :: !a1
      done
    with _ -> begin
        let deplist = a13 !a1 in
        let tasklist = a14 !a1 in
        let starters = a17 (a16 0 deplist tasklist) in
        try begin
            let topsorted = a21 deplist tasklist starters [] in
            if List.length tasklist != List.length topsorted then
              raise (Failure "cycle");
            List.iter print_endline topsorted;
          end
        with Failure explanation -> print_endline explanation
      end
