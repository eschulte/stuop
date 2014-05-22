type a13 = {
  a14 : string list;
  a15 : int
} ;;
module A16 = Map.Make(String);;
let a1 = ref A16.empty in
    try
      while true do
        let a2 = (read_line ()) in
        let a3 = (read_line ()) in
        a1 := if A16.mem a3 !a1 then
                A16.add a3
                        {
                          a14 = a2 :: (A16.find a3 !a1).a14;
                          a15 = (A16.find a3 !a1).a15;
                        }
                        !a1
              else
                A16.add a3 {a14=(a2::[]);a15=0} !a1;
        a1 := if A16.mem a2 !a1 then
                A16.add a2
                        {
                          a14 = (A16.find a2 !a1).a14;
                          a15 = (A16.find a2 !a1).a15 + 1;
                        }
                        !a1
              else
                A16.add a2 {a14=[];a15=1} !a1;
      done
    with _ -> begin
        let rec a9 a6 =
          if A16.is_empty !a1 then
            a6
          else
            let a10 a8 a5 = a5.a15 = 0 in
            let a4 = A16.filter a10 !a1 in
            if A16.is_empty a4 then
              ["cycle"]
            else
              let a11 a8 a5 a6 =
                if compare a6 "" = 0 then
                  a8
                else
                  if compare a8 a6 <= 0 then
                    a8
                  else
                    a6
              in
              let a7 = A16.fold a11 a4 "" in
              let a12 a8 =
                a1 := A16.add a8
                              {
                                a14 = (A16.find a8 !a1).a14;
                                a15 = (A16.find a8 !a1).a15 - 1;
                              } !a1 in
              List.iter a12 (A16.find a7 !a1).a14;
              a1 := A16.remove a7 !a1;
              let a6 = a6 @ [a7] in
              a9 a6
        in
        List.iter print_endline (a9 [])
      end
